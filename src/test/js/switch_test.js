switch ( type ) {
case "only":
case "first":
	while ( (node = node.previousSibling) )	 {
		if ( node.nodeType === 1 ) { 
			return false; 
		}
	}

	if ( type === "first" ) { 
		return true; 
	}

	node = elem;

case "last":
	while ( (node = node.nextSibling) )	 {
		if ( node.nodeType === 1 ) { 
			return false; 
		}
	}

	return true;

case "nth":
	first = match[2];
	last = match[3];

	if ( first === 1 && last === 0 ) {
		return true;
	}
	
	doneName = match[0];
	parent = elem.parentNode;
	
	if ( parent && (parent[ expando ] !== doneName || !elem.nodeIndex) ) {
		count = 0;
		
		for ( node = parent.firstChild; node; node = node.nextSibling ) {
			if ( node.nodeType === 1 ) {
				node.nodeIndex = ++count;
			}
		} 

		parent[ expando ] = doneName;
	}
	
	diff = elem.nodeIndex - last;

	if ( first === 0 ) {
		return diff === 0;

	} else {
		return ( diff % first === 0 && diff / first >= 0 );
	}
  break;
default :
  console.log(1);
}