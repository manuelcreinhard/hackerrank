my $cases = <>;
chomp $cases;
for(my $i = 0; $i < $cases;$i++){
	my $line = <>;
	chomp $line;
	if($line =~ /\((-*\+*[1-9]+[0-9]*(\.[0-9]+)*)\s*,\s*(-*\+*[1-9]+[0-9]*(\.[0-9]+)*)\)/i){
		if($1 >= -90 && $1 <= 90 && $3 >= -180 && $3 <= 180){
			print "Valid\n";
		} else {
			print "Invalid\n";
		}
	} else {
		print "Invalid\n";
	}
}
