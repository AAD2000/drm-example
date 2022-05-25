#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xd9726f80, "module_layout" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x1bcee483, "cdev_del" },
	{ 0x64b60eb0, "class_destroy" },
	{ 0xe340d421, "device_destroy" },
	{ 0x68de7c4, "platform_driver_unregister" },
	{ 0x9f4f34bc, "device_create" },
	{ 0xa946dcde, "__class_create" },
	{ 0xa747f323, "drm_dev_register" },
	{ 0x21e53299, "drm_dev_alloc" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "drm");


MODULE_INFO(srcversion, "186B0E11894041BE7DAD6FB");
