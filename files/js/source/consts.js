import {funcUtils} from 'func_utils'
module consts {
  export index = {
    BG_CACHE : funcUtils.memoize(->$("#bg")),
    LINE_CACHE : funcUtils.memoize(->$('#line'))
  }
  export api = {
    LEFT_BLOCK : funcUtils.memoize(->$("#leftBlock")),
    LEFT_A_SELECTOR : "#leftBlock li a"
  }
}