require 'socket'

while true
host ="192.168.223.128"
port = 3000
server = TCPServer.open(host,port)

loadbalancer = server.accept
puts loadbalancer.gets
loadbalancer.close
server.close

end