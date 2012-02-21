#ifndef mocha_atof_h_
#define mocha_atof_h_

namespace mocha {

class Atof {
 public :
  static Convert( const char* str ) {
    int sign = _space_sign(s, &s);
    int result;
    for (result = 0; isdigit((unsigned char)*s); s++)
      result = result * 10 + *s - '0';
    if (sign != 0)
      result = -result;
    return result;
  }
}

}

#endif
