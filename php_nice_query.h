#ifndef PHP_NICE_QUERY_H
#define PHP_NICE_QUERY_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include "php.h"
#include "php_ini.h"

ZEND_BEGIN_MODULE_GLOBALS(nice_query)
long counter;
ZEND_END_MODULE_GLOBALS(nice_query)

#define PHP_NICE_QUERY_VERSION "0.0.1"
#define PHP_NICE_QUERY_EXTNAME "nice_query"

#ifdef ZTS
#define NICE_QUERY_G(v) TSRMG(nice_query_globals_id, zend_nice_query_globals *, v)
#else
#define NICE_QUERY_G(v) (nice_query_globals.v)
#endif


PHP_FUNCTION(hello_world);

PHP_MINIT_FUNCTION(nice_query);

PHP_MSHUTDOWN_FUNCTION(nice_query);

PHP_RINIT_FUNCTION(nice_query);

extern zend_module_entry nice_query_module_entry;
#define phpext_nice_query_ptr &nice_query_module_entry

#endif
