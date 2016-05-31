#include "php.h"
#include "slobel_darray.h"

zend_class_entry *slobe_darray_class;

PHP_METHOD(slobe_darray, say_hello) {
	RETURN_STRING("Hi, Nihao", 1);
}

PHP_METHOD(slobe_darray, self) {
	zval *obj;

	obj = getThis();

	RETURN_ZVAL(obj, 1, 0);
}

const zend_function_entry slobel_darray_functions[] = {
	PHP_ME(slobe_darray, say_hello, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(slobe_darray, self, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

void slobel_darray_init(TSRMLS_D) {
	zend_class_entry tmp;

	INIT_CLASS_ENTRY(tmp, "slobe_darray", slobel_darray_functions);

	slobe_darray_class = zend_register_internal_class(&tmp TSRMLS_CC);

	return ;
}