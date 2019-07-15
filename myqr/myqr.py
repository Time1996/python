from MyQR import myqr
import  os
version, level, qr_name = myqr.run(
    words = 'https://www.baidu.com',
    version=1,
    level = 'H',
    picture = 'template-banner.png',
    colorized = True,
    contrast = 1.0,
    brightness = 1.0,
    save_name = 'mysqr.png',
    save_dir = os.getcwd()
)