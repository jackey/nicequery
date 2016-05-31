#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_nice_query.h"
#include "slobel_darray.h"

#define NICE_QUERY_VERSION "1.0.0"
#define NICE_QUERY_EXTNAME "nice_query"

extern zend_module_entry nice_query_module_entry;

static zend_function_entry functions[] = {
	PHP_FE(hello_world, NULL)
	PHP_FE(your_langugae, NULL)
	{NULL, NULL, NULL}
};


PHP_MINIT_FUNCTION(nice_query) {
	slobel_darray_init(TSRMLS_C);
	return SUCCESS;
}

zend_module_entry nice_query_module_entry = {
	#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
	#endif
	NICE_QUERY_EXTNAME,
	functions,
    PHP_MINIT(nice_query), // name of the MINIT function or NULL if not applicable
    NULL, // name of the MSHUTDOWN function or NULL if not applicable
    NULL, // name of the RINIT function or NULL if not applicable
    NULL, // name of the RSHUTDOWN function or NULL if not applicable
    NULL, // name of the MINFO function or NULL if not applicable
    #if ZEND_MODULE_API_NO >= 20010901
    NICE_QUERY_VERSION,
    #endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(nice_query);

PHP_FUNCTION(hello_world) {
	RETURN_STRING("HELLO WORLD", 1);
}

PHP_FUNCTION(your_langugae) {
	zend_bool english = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &english) == FAILURE) {
		return;
	}

	if (english) {
		php_printf("I'm English !");
	}
	else {
		php_printf("I'm not english ");
	}

	zval *arr;

	MAKE_STD_ZVAL(arr);
	array_init(arr);

	add_next_index_string(arr, "yes", 1);

	*return_value = *arr;
}

