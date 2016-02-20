#ifndef PHP_NICE_QUERY_H
#define PHP_NICE_QUERY_H

#define PHP_NICE_QUERY_VERSION "0.0.1"
#define PHP_NICE_QUERY_EXTNAME "nice_query"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

PHP_FUNCTION(hello_world);

extern zend_module_entry nice_query_module_entry;
#define phpext_nice_query_ptr &nice_query_module_entry


#endif
