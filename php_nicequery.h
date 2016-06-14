#ifndef PHP_NICEQUERY_H
#define PHP_NICEQUERY_H

#if HAVE_CONFIG_H
#include "config.h"
#endif

#define PHP_NICEQUERY_VERSION "0.0.1"

#ifdef ZTS
#include "TSRM.h"
#endif

#include "php.h"

extern zend_module_entry nicequery_module_entry;

#define phpext_nicequery_ptr &nicequery_module_entry;

#endif
