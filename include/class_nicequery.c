/*
 * class_nicequery.c
 *
 *  Created on: Jun 11, 2016
 *      Author: jackeychen
 */
#include "class_nicequery.h"
#include "php.h"

#ifdef ZTS
#include "TSRM.h"
#endif

const zend_function_entry class_methods[] = {
		PHP_METHOD_END
};

zend_class_entry *cls_nicequery;


void register_class_nicequery() {
	zend_class_entry cls_tmp;
	INIT_CLASS_ENTRY(cls_tmp, "NiceQuery", class_methods);

	cls_nicequery = zend_register_;
}

