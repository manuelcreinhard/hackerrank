$i=0;
while ($i++<100) {
$s="";
$s.= "Fizz" if !($i%5);
$s.= "Buzz" if !($i%3);
$s = $s || $i;
print "$s\n";
}

