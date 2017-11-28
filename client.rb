require 'socket'

host = "192.168.79.130"
port = 1500

client = TCPSocket.open(host,port)

puts "Enter Your Message : "
message=gets.chomp

loadhost=client.peeraddr.last
puts "#{loadhost}"
client.write(message)
client.close

