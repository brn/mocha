var fmt = require( "./fmt" ).fmt

const main () {
        fmt( "${hello} ${world}" , {
          hello : "hello",
          world : "world"
        })
      }