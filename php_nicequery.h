#ifndef PHP_NICEQUERY_H
#define PHP_NICEQUERY_H

#if HAVE_CONFIG_H
#include "config.h"
#endif

#define PHP_NICEQUERY_VERSION "0.0.1"

#include "php.h"

extern zend_module_entry extnicequery_module;
#define phpext_nicequery_ptr &extnicequery_module;



#endif
