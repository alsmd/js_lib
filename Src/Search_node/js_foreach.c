#include <js_lib.h>

/*
	@brief		execute func in each node of the array
	@param		array (a t_json_obj that has the type JSON_ARRAY)
	@param		func (pass each array's node to this function)
*/
void	js_foreach(t_json_obj *array, void (*func)(t_json_obj *item))
{
	t_json_obj	*begin;

	begin = array->array_value;
	while (begin)
	{
		func(begin);
		begin = begin->next;
	}
}
