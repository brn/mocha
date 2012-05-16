
module agent {
  var {userAgent} = navigator,
      {appName} = navigator,
      agent = {
        IE6 : userAgent.indexOf('IE 6') > -1,
        IE7 : userAgent.indexOf('IE 7') > -1,
        IE8 : userAgent.indexOf('IE 8') > -1
      }
  agent.{
    legacy : agent.IE6 || agent.IE7 || agent.IE8
  }
  export agent;
}
