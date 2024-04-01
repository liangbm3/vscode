import logging
def log_testing():
    selflogger = logging.getLogger('THIS-LOGGING')
    logging.basicConfig(filename='log.log',
                     format = '%(thread)d - %(asctime)s - %(funcName)s - %(levelname)s - %(message)s',
                     level=logging.INFO)
    selflogger.info("alalla")
    selflogger.warning('waring，用来用来打印警告信息')
    selflogger.error('error，一般用来打印一些错误信息')
    selflogger.critical('critical，用来打印一些致命的错误信息，等级最高')

log_testing()