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
#define NICE_QUERY_G(v) TSRMG(nicequery_globals_id, zend_nicequery_globals *, v)
#else
#define NICE_QUERY_G(v) nicequery_globals.v
#endif

zend_function_entry nicequery_functions[] = {
		{NULL, NULL, NULL}
};

// 模块初始化执行函数
PHP_MINIT_FUNCTION(nicequery) {
	//TODO:: 定义class
	return SUCCESS;
}

// 模块退出执行函数
PHP_MSHUTDOWN_FUNCTION(nicequery) {
	return SUCCESS;
}

// 每次 request 过来执行的函数
PHP_RINIT_FUNCTION(nicequery){
	return SUCCESS;
}

// 每次request 结束后执行的函数
PHP_RSHUTDOWN_FUNCTION(nicequery) {
	return SUCCESS;
};

PHP_MINFO_FUNCTION(nicequery) {
	php_info_print_table_start();
		php_info_print_table_header(2, "nicequery extension", "enabled");
		php_info_print_table_row(2, "nicequery version", PHP_NICEQUERY_VERSION);
		php_info_print_table_row(2, "author", "jackey <jackey@fumer.cn>");
	php_info_print_table_end();
}

zend_module_entry nicequery_module_entry =
{
		STANDARD_MODULE_HEADER,
		"nicequery", //name of the extension
		nicequery_functions,
		PHP_MINIT(nicequery),
		PHP_MSHUTDOWN(nicequery),
		PHP_RINIT(nicequery),
		PHP_RSHUTDOWN(nicequery),
		PHP_MINFO(nicequery),
		PHP_NICEQUERY_VERSION,
		STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_EXTNICEQUERY
ZEND_GET_MODULE(nicequery)
#endif
