class Myclass:
    name = 'Sam'
    def sayHi(self):
        print('Hello %s' % self.name)
mc = Myclass()
print(mc.name)
mc.name = 'Lilly'
mc.sayHi()