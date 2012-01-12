module global {
  
  export global = ( this !== undefined || this !== null )? 
    this : ( typeof window === "object" )? 
    window : ( typeof global === "object" )? global : {};
  
}