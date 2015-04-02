my $count = <>;
while($count--){
	my $str = <>;
	makePalind($str);
}

sub makePalind{
	my $str = shift;
	my @chars = split("",$str);
	my $length = length($str) - 1;
	my $impair = $length%2;
	my $half = ($length-$impair)/2;
	#print "Length: $length\n";
	#print "Half: $half\n";
	for(my $i = 0;$i<$half;$i++){
		#print "st: $chars[$i] end: $chars[$length-$i-1]\n";
		next if ($chars[$i] eq $chars[$length-$i-1]);
		if($chars[$i+1] eq $chars[$length-$i-1]){
			print "$i\n";
			return;
		} else {
			my $temp = $length - $i -1;
			print "$temp\n";
			return;
		}
	}
	print "-1\n";
}
