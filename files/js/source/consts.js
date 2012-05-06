import {Functions} from 'functions'
module consts {
  export index = {
    BG_CACHE : Functions.memoize(->$("#bg"))
  }
  export api = {
    LEFT_BLOCK : Functions.memoize(->$("#leftBlock")),
    LEFT_A_SELECTOR : "#leftBlock li a"
  }
}