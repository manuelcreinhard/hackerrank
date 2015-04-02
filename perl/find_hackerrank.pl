# Enter your code here. Read input from STDIN. Print output to STDOUT
my $cases = <>;
chomp $cases;
for(my $i = 0; $i<$cases;$i++){
   my $line = <>;
   chomp $line;
   my $start = 0;
   my $end = 0;
   $start = 1 if $line =~ /^hackerrank/;
   $end = 1 if $line =~ /hackerrank$/;
   if($start && $end){
	   print "0\n";
	   next;
   }
   if($start){
	   print "1\n";
	   next;
   } elsif ($end){
	   print "2\n";
	   next;
   }
   print "-1\n";
   
   
}
