#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_nice_query.h"

static function_entry nice_query_functions[] = {
	PHP_FE(hello_world, NULL),
	{NULL, NULL, NULL}
};

zend_module_entry nice_query_module_entry = {
	#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
	#endif

	PHP_NICE_QUERY_EXTNAME,
	nice_query_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	#if ZEND_MODULE_API_NO >= 20010901
    PHP_NICE_QUERY_VERSIOn,
	#endif
	STANDARD_MODULE_PROPERTIES
};

PHP_FUNCTION(hello_world) {
	RETURN_STRING("Hello, world", 1);
}

