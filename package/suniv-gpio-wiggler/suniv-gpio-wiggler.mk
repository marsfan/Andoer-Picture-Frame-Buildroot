SUNIV_GPIO_WIGGLER = 1.0
# SUNIV_GPIO_WIGGLER_SITE = &amp;lt;strong&amp;gt;../path/to/your/source/code/test&amp;lt;/strong&amp;gt;
SUNIV_GPIO_WIGGLER_SITE=$(SUNIV_GPIO_WIGGLER_PKGDIR)src
SUNIV_GPIO_WIGGLER_SITE_METHOD = local
SUNIV_GPIO_WIGGLER_INSTALL_TARGET = YES
SUNIV_GPIO_WIGGLER_DEPENDENCIES = libgpiod

define SUNIV_GPIO_WIGGLER_BUILD_CMDS
$(MAKE) CC="$(TARGET_CC)" LD="$(TARGET_LD)" -C $(@D) all
endef

define SUNIV_GPIO_WIGGLER_INSTALL_TARGET_CMDS
$(INSTALL) -D -m 0755 $(@D)/gpio-wiggler $(TARGET_DIR)/bin
endef

$(eval $(generic-package))