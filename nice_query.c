#include "php_nice_query.h"

ZEND_DECLARE_MODULE_GLOBALS(nice_query)

static zend_function_entry nice_query_functions[] = {
	PHP_FE(hello_world, NULL)
	{NULL, NULL, NULL}
};

zend_module_entry nice_query_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_NICE_QUERY_EXTNAME,
	nice_query_functions,
	PHP_MINIT(nice_query),
	PHP_MSHUTDOWN(nice_query),
	PHP_RINIT(nice_query),
	NULL,
	NULL,
	PHP_NICE_QUERY_VERSION,
	STANDARD_MODULE_PROPERTIES
};

PHP_INI_BEGIN()
PHP_INI_ENTRY("nice_query.host", "127.0.0.1", PHP_INI_ALL, NULL)
PHP_INI_ENTRY("nice_query.port", "3306", PHP_INI_ALL, NULL)
PHP_INI_ENTRY("nice_query.db", "unknow", PHP_INI_ALL, NULL)
PHP_INI_ENTRY("nice_query.user", "root", PHP_INI_ALL, NULL)
PHP_INI_ENTRY("nice_query.pwd", "admin", PHP_INI_ALL, NULL)
PHP_INI_ENTRY("nice_query.charset", "utf8", PHP_INI_ALL, NULL)
PHP_INI_END()

static void php_nice_query_init_globals(zend_nice_query_globals *nice_query_globals) {
	//
}

PHP_FUNCTION(hello_world) {

	NICE_QUERY_G(counter) ++;

	RETURN_LONG(NICE_QUERY_G(counter));
}

PHP_MINIT_FUNCTION(nice_query) {

	ZEND_INIT_MODULE_GLOBALS(nice_query, php_nice_query_init_globals, NULL);

	REGISTER_INI_ENTRIES();

	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(nice_query) {
	UNREGISTER_INI_ENTRIES();

	return SUCCESS;
}

PHP_RINIT_FUNCTION(nice_query) {
	NICE_QUERY_G(counter) = 0;

	return SUCCESS;
}


#ifdef COMPILE_DL_NICE_QUERY
ZEND_GET_MODULE(nice_query)
#endif