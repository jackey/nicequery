<?php

class NiceQueryInsert {
	/**
	 * TODO::
	 */
}

class NiceQuerySelect {
	select();

	where();

	orWhere();

	andWhere();

	sqlWhere();

	limit();

	offset();

	

}

class NiceQueryUpdate() {
	/**
	 * TODO::
	 */
}


class NiceQuery {
	/**
	 * 返回一个 NiceQuerySelect 对象
	 */
	from(); 

	/**
	 * 返回一个 NiceQueryUpdate 对象
	 */
	update(); 

	/**
	 * 返回一个 NiceQueryDelete 对象
	 */
	delete();

	/**
	 * 返回一个 NiceQueryInsert 对象 
	 */
	insert();

	/**
	 * 返回一个 NiceQuerySQL 对象
	 */
	sql();

	static configTables();

	static configDatabases();
}

$tables = array(
	// pk -> 主键
	// mk -> 分表建
	// type -> 分表类型
	// ... -> 对应分表类型参数
	't_log' => array('db' => 'db_log' , 'pk' => 'Fid', 'mk' => 'Fid', 'type' => 'date', 'format' => 'Ymd'), // 日期分表 - 日期格式
	't_user' => array('db' => 'db_business',  'pk' => 'Fid', 'mk' => 'Fid', 'type' => 'hash', 'len' => '6'), // hash分表 - hash结果取字符长度
	't_post' => array('db' => 'db_business', 'pk' => 'Fid', 'mk' => 'Fid', 'type' => 'rand', 'range' => 1<<20) // 范围分表 - 每隔 range 长度后 新建表
);

$databases = array(
	'db_business' => array(
		'host' => '127.0.0.1',
		'db' => 'db_user',
		'password' => 'admin',
		'user' => 'root',
		'charset' => 'utf8mb4'
	),
	'db_log' => array(
		'host' => '127.0.0.1',
		'db' => 'db_log',
		'password' => 'admin',
		'user' => 'root',
		'charset' => 'utf8mb4',
	)
);

NiceQuery::configTables($tables);
NiceQuery::configDatabases($databases);

$query = NiceQuery::new();

/**
 * 查找API
 */
// 主键查找
$query->from('t_user');
$ret = $query->findByPk();

// 条件查找
$query->from('t_user');
$query->select('*');
$query->where('Fcreated', $now, '>=');
$query->andWhere('Flast_login', $now, '<=');
$query->whereSQL('( Fcreated > ? AND Fupdate > ? ) OR (Fstatus = 0)', array($now, $now, $now));
$query->limit(20);
$query->offset(0);
$result = $query->all();
$result = $query->one();

/**
 * 新增数据 API
 */
$query->insert('t_user');
$query->values(array(
	'Fname' => 'jackey',
	'Fpassword' => 'xxxx',
	'Fcreated' => time()
));
$query->execute();

/**
 * 修改数据 API
 */
$query->update('t_user');
$query->where('Fcreated ', $now, '>');
$query->whereSQL('( Fcreated > ? AND Fupdate > ? ) OR (Fstatus = 0)', array($now, $now, $now));
$query->values(array(
	'Fname' => 'jackeychen',
));
$query->update();
























