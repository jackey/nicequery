PHP_ARG_ENABLE(nice_query, whether to enable nice query support, 
	[--enable-nice_query              Enbale Nice Query support])

if test $PHP_NICE_QUERY = "yes"; then 
	PHP_NEW_EXTENSION(nice_query, nice_query.c, $ext_shared)
fi