#include <js_lib.h>

/*
	@brief	Search inside the t_json_obj for the attribute that has key.
	@param	obj (t_json_obj that is the base of the search)
	@param	key (what attribute we want to find)
	@return	Returns a t_json_obj that is the attribute found or 0 if not found.
*/
t_json_obj	*js_get_value(t_json_obj *obj, char *key)
{
	t_json_obj	*begin;

	begin = obj;
	while (begin)
	{
		if (!strcmp(begin->key, key))
			return (begin);
		begin = begin->next;
	}
	return (0);
}