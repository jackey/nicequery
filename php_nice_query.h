#ifndef NICE_QUERY_H
#define NICE_QUERY_H

#define PHP_NICE_QUERY_VERSION "1.0"
#define PHP_NICE_QUERY_EXTNAME "nice_query"

PHP_FUNCTION(hello_world);

PHP_FUNCTION(your_langugae);

extern zend_module_entry nice_query_module_entry;

#define phpext_nice_query_ptr &nice_query_module_entry;

#endif
