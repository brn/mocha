#include <mocha/roaster/ast/values/js_values.h>

namespace mocha {

JSValue* JSArray::Clone() {
	JSArray* array = JSArray::New();
	for ( int i = 0,len = elements_.size(); i < len; i++ ) {
		JSValue* item = elements_.at( i );
		array->element( item );
	}
	array->ref( ref() );
	return array;
}

JSValue* JSObject::Clone() {
	JSObject* object = JSObject::New();
	JSPropertyIterator iterator = Properties();
	while ( iterator.HasNext() ) {
		JSPropertyEntry ent = iterator.Next();
		object->property( ent.Key().c_str() , ent.Value() );
	}
	object->ref( ref() );
	return object;
}

JSValue* JSFunction::Clone() {
	JSFunction* function = JSFunction::New( name_ );
	function->flgs_ = flgs_;
	function->ref( ref() );
	return function;
}

JSValue* JSLiteral::Clone() {
	JSLiteral* literal = JSLiteral::New( value_ );
	return literal;
}

}
