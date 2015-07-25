#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_alsps.h>

static struct alsps_hw cust_alsps_hw = {
    .i2c_num    = 2,
	.polling_mode_ps =0,
	.polling_mode_als =1,
    .power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
    .power_vol  = VOL_DEFAULT,          /*LDO is not used*/
    //.i2c_addr   = {0x0C, 0x48, 0x78, 0x00},
    .als_level  = { 0,  1,  1,   7,  15,  15,  100, 1000, 2000,  3000,  6000, 10000, 14000, 18000, 20000},
    .als_value  = {40, 40, 90,  90, 160, 160,  225,  320,  640,  1280,  1280,  2600,  2600, 2600,  10240, 10240},
#if 0 //+++rgk sync same config to j509 old by anxiang.xiao 20140311
	.ps_threshold_high = 130, 
	.ps_threshold_low = 120,
#else
	//+++rgk make sensor more easier to be far by anxiang.xiao 20140320
	#if 0
	.ps_threshold_high = 16,
	.ps_threshold_low = 6,
	#else
	.ps_threshold_high = 16,
	.ps_threshold_low = 9,
	#endif
#endif
};
struct alsps_hw *get_cust_alsps_hw(void) {
    return &cust_alsps_hw;
}
