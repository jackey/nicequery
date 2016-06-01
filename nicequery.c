/*
 * nice_query.c
 *
 *  Created on: Jun 1, 2016
 *      Author: jackeychen
 */

#include "php_nicequery.h"
#include "ext/standard/info.h"

/**
 * 全局配置信息 - 暂无
 */
ZEND_BEGIN_MODULE_GLOBALS(nicequery)
	char *simple_name;
ZEND_END_MODULE_GLOBALS(nicequery)

ZEND_DECLARE_MODULE_GLOBALS(nicequery)

#ifdef ZTS
#define EXTNICE_QUERY_G(v) TSRMG(extnicequery_globals_id, zend_nicequery_globals *, v)
#else
#define EXTNICE_QUERY_G(v) extnicequery_globals.v
#endif

zend_function_entry extnicequery_functions[] = {
		{NULL, NULL, NULL}
};

// 模块初始化执行函数
PHP_MINIT_FUNCTION(extnicequery) {
	//TODO:: 定义class
}

// 模块退出执行函数
PHP_MSHUTDOWN_FUNCTION(extnicequery) {
	//TODO::
}

// 每次 request 过来执行的函数
PHP_RINIT_FUNCTION(extnicequery){
	//TODO::
}

// 每次request 结束后执行的函数
PHP_RSHUTDOWN_FUNCTION(extnicequery) {
	//TODO::
}

PHP_MINFO_FUNCTION(extnicequery) {
	php_info_print_table_start();
		php_info_print_table_header(2, "extnicequery extension", "enabled");
		php_info_print_table_row(2, "extnicequery version", PHP_NICEQUERY_VERSION);
	php_info_print_table_end();
}

zend_module_entry extnicequery_module_entry =
{
		STANDARD_MODULE_HEADER,
		"extnicequery", //name of the extension
		extnicequery_functions,
		PHP_MINIT(extnicequery),
		PHP_MSHUTDOWN(extnicequery),
		PHP_RINIT(extnicequery),
		PHP_RSHUTDOWN(extnicequery),
		PHP_MINFO(extnicequery),
		PHP_NICEQUERY_VERSION,
		STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_EXTNICEQUERY
ZEND_GET_MODULE(extnicequery)
#endif
