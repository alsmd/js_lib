#ifndef JS_LIB_H
#define JS_LIB_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

typedef enum e_json_type
{
	JSON_NULL,
	JSON_OBJ,
	JSON_ARRAY,
	JSON_STRING,
	JSON_INTEGER,
	JSON_DOUBLE,
	JSON_BOOL
}	t_json_type;

typedef struct s_json_obj
{
	t_json_type			type;
	char				*key;
	char				*string_value;
	int					int_value;
	struct s_json_obj	*obj_value;
	struct s_json_obj	*array_value;
	struct s_json_obj	*next;
}	t_json_obj;

/*
	@brief	Convert a json string into a json_obj and returns it.
*/
t_json_obj	*js_convert_to_object(char *j);

/***************
 * 
 * 	CREATE NODES
 * 
****************/

char	*js_new_obj_attr(char *json, t_json_obj *obj);
char	*js_new_array_attr(char *json, t_json_obj *obj);
char	*js_new_obj(char *json, t_json_obj *obj);
char	*js_new_array(char *json, t_json_obj *obj);
char	*js_new_string(char *json);
/***************
 * 
 * 	SEARCH NODES
 * 
****************/

t_json_obj	*js_get_value(t_json_obj *obj, char *key);
void		js_foreach(t_json_obj *array, void (*func)(t_json_obj *item));


/***************
 * 
 * 	UTILS
 * 
****************/

int		is_number(char c);
int		strlen_var(char *buffer, char end);
int		is_whitespace(char c);
char	*jump_whitespace(char *str);

#endif