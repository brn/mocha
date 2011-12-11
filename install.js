var fs = require( "fs" ),
    bin_path = process.argv[ 1 ],
    target_path = ( process.env.HOMEDRIVE + process.env.HOMEPATH + "/.mocha" ).replace( /\\/g , "/" );

var install = function () {
      mkdir( target_path );
      rec_cp( get_setting_path() , target_path , {} );
    }


var get_name_from_path = function( path ) {
      var last_index = path.lastIndexOf( "/" );
      if ( last_index === -1 ) {
        last_index = path.lastIndexOf( "\\" );
      }
      return path.slice( last_index + 1 );
    }

var get_setting_path = function () {
      var last_index = bin_path.lastIndexOf( "/" );
      if ( last_index === -1 ) {
        last_index = bin_path.lastIndexOf( "\\" );
      }
      return bin_path.slice( 0 , last_index + 1 ) + "mocha";
    }


var mkdir = function( path , callback ) {
      fs.mkdir( path , 0777 , function ( err ){
        if ( err ) {
          var exist = err.message.indexOf( "EEXIST" ) > -1;
          if ( exist ) {
            console.log( path + " is already exist. you run install.js twice?\nIf you not, then remove cause of error and try again." );
          }
          process.exit();
        }
        callback && callback();
      });
    }


var check_dir_or_file = function ( path , callbacks ) {
      fs.stat( path , function ( err , stats ) {
        if ( stats.isFile() ) {
          callbacks.file && callbacks.file( path , stats );
        } else if ( stats.isDirectory() ) {
          callbacks.dir && callbacks.dir( path , stats );
        } else {
          callbacks.missing && callbacks.missing( path , stats , err );
        }
      });
    }


var touch = function ( path , callback ) {
      fs.open( path , "a+" , function ( err , fd ){
        fs.closeSync( fd );
        if ( err ) {
          console.log( err.message );
          process.exit();
        }
        callback && callback();
        
      })
    }



var rec_cp = function ( current_dir , dest_path , memo ) {
      var dir = [];
      fs.readdir( current_dir , function ( err , path_arr ) {
        path_arr.forEach(function ( path , index ) {
          check_dir_or_file( current_dir + '/' + path , {
            file : function ( current_dir , dest_path , path , stats ) {
              var processed_path = get_name_from_path( path ),
                  dest_file = dest_path + '/' + processed_path;
              
              touch( dest_file , function () {
                if ( !memo[ dest_file ] ) {
                  memo[ dest_file ] = 1;
                  var cp_inst = new cp( dest_file , current_dir + '/' + processed_path );
                  cp_inst.write();
                }
              });
            }.bind( null , current_dir , dest_path ),
            
            dir : function ( current_dir , dest_path , path , stats ) {
              var processed_path = get_name_from_path( path );
              current_dir += '/' + processed_path;
                  dest_path += '/' + processed_path;
              mkdir( dest_path , rec_cp.bind( null , current_dir , dest_path , memo ) );
            }.bind( null , current_dir , dest_path ),
            
            missing : function ( current_dir , dest_path , path , stats , err ) {
              console.log( err.message );
              process.exit();
            }
          });
        });
      });
    }


var cp = function ( dest , source ) {
      this._read  = fs.createReadStream( source );
      this._write = fs.createWriteStream( dest );
    }

cp.prototype.write = function() {
  this._read.on( 'data', function ( data ) {
    data.write( data.toString() );
  });
  this._read.pipe(this._write);
}


install();
