
require 'socket'

host = "192.168.79.130"
port = 1500
loadbalancer = TCPServer.open(host,port)

while true
client = loadbalancer.accept

loadhost=client.peeraddr.last
puts "#{loadhost} connect to loadbalancer"

fromclient=client.gets
puts "Message from client : #{fromclient}"

if fromclient=="friend"
sockettoserver1 = TCPSocket.open("192.168.223.128",3000)
sockettoserver1.write(fromclient)
sockettoserver1.close

else if fromclient=="enemy"
sockettoserver2 = TCPSocket.open("192.168.223.131",4000)
sockettoserver2.write(fromclient)
sockettoserver2.close

else
puts "ERROR"

end
end
end
