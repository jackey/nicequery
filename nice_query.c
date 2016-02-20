#include "php_nice_query.h"

static zend_function_entry nice_query_functions[] = {
	PHP_FE(hello_world, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry nice_query_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_NICE_QUERY_EXTNAME,
	nice_query_functions,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	PHP_NICE_QUERY_VERSION,
	STANDARD_MODULE_PROPERTIES
};

PHP_FUNCTION(hello_world) {
	RETURN_STRING("Hello, world", 1);
}

#ifdef COMPILE_DL_NICE_QUERY
ZEND_GET_MODULE(nice_query)
#endif