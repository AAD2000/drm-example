#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <drm/drm.h>
#include <linux/platform_device.h>
#include <drm/drm_drv.h>

#include <linux/mod_devicetable.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/ioctl.h>

static struct drm_driver my_drm;
dev_t dev = 0;

static struct class *dev_class;
static struct cdev etx_cdev;



static int my_drm_platform_probe(struct platform_device *pdev)
{
	struct drm_device *drm;
    printk("===== DRM PLATFORM PROBE =====");

    drm = drm_dev_alloc(&my_drm, &pdev->dev);


    int res2 = drm_dev_register(drm, 0);

    if(res2 == 0){
        printk("----- SUCCESS -----");
    } else {
        printk("----- ERROR -----");
    }

    return 0;
}
static int my_drm_platform_remove(struct platform_device *pdev)
{
    return 0;
}

static const struct of_device_id my_of_ids[] = {
	{ .compatible = "long,my-drm" }
};

static struct platform_driver my_drm_private_driver = {
	.probe			= my_drm_platform_probe,
	.remove			= my_drm_platform_remove,
	.driver			= {
		.name	        = "my-drm",
		.of_match_table = my_of_ids,
	},
};

static int __init etx_driver_init(void)
{
    /*Creating struct class*/
        if((class_create(THIS_MODULE,"etx_class2")) == NULL){
            pr_err("Cannot create the struct class\n");
            
        }
 
        /*Creating device*/
        if((device_create(dev_class,NULL,dev,NULL,"my-drm")) == NULL){
            pr_err("Cannot create the Device 1\n");
           
        }
   
    //int i = platform_driver_register(&my_drm_private_driver);
    //printk("hello im registered %d", i);

    struct drm_device *drm;
    printk("===== DRM PLATFORM PROBE =====");

    drm = drm_dev_alloc(&my_drm, dev);


    int res2 = drm_dev_register(drm, 0);

    if(res2 == 0){
        printk("----- SUCCESS -----");
    } else {
        printk("----- ERROR -----");
    }

	return 0;    
}

/*
** Module exit function
*/
static void __exit etx_driver_exit(void)
{
    platform_driver_unregister(&my_drm_private_driver);
    device_destroy(dev_class,dev);
    class_destroy(dev_class);
    cdev_del(&etx_cdev);
    unregister_chrdev_region(dev, 1);
}

module_init(etx_driver_init);
module_exit(etx_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AAD");
MODULE_DESCRIPTION("Simple Linux drm device driver");
MODULE_VERSION("1.0");
