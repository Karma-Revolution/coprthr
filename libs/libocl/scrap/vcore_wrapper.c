
#include "vcore.h"
#include "util.h"

/* XXX this file should eventually be autogenerated -DAR */


typedef void(*func_3_xxx_t)(void*,void*,void*);
void wrapper_3_xxx( void* p )
{
	DEBUG(__FILE__,__LINE__,"vcore_wrapper_3_xxx");

	struct vcengine_data* edata = (struct vcengine_data*)p;
	struct vc_data* data = __getvcdata();
	int vcid = data->vcid;

	DEBUG(__FILE__,__LINE__,"vcore[%d] running\n",vcid);

	++edata->vc_runc;

	/* execute kernel */
	((func_3_xxx_t)(edata->funcp))(
		(void*)edata->pr_arg_vec[0],
		(void*)edata->pr_arg_vec[1],
		(void*)edata->pr_arg_vec[2]
	);

	DEBUG(__FILE__,__LINE__,"funcp %p",edata->funcp);
	DEBUG(__FILE__,__LINE__,"arg0[2] %d",((int*)edata->pr_arg_vec[0])[2]);
	DEBUG(__FILE__,__LINE__,"arg1[2] %d",((int*)edata->pr_arg_vec[1])[2]);
	DEBUG(__FILE__,__LINE__,"arg2[2] %d",((int*)edata->pr_arg_vec[2])[2]);

	--edata->vc_runc;

	DEBUG(__FILE__,__LINE__,"vcore[%d] halt\n",vcid);
}


void* vcore_v[] = {
	(void*)wrapper_3_xxx
};





