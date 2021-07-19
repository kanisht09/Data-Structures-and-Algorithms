* #### Prefix array can be used for range queries with no updates
* Prefix sum and prefix XOR can be used for range queries.
* Prefix min and max can be made but they can't be used for queries as their inverse doesn't exists( for example the inverse of addition is subtraction and the inverse of Xor is itself).
* For min-max range queries segment trees can be used.
* #### Numbers which are perfect squares have odd number of divisors.
* If the number is odd, it has only odd divisors and an even number not divisible by 4 will have same number of odd and even divisors and even number will have more number of even divisors if it is divisible by 4. 
* xenodrome number : a number which has distinct digits in a particular base.
* An odd composite number can be written as the difference of two squares of a number.
* A number cannot have more than log(N) primes.
* The average gap between consecutive prime numbers among the first N integers is roughly log(N).
* The count of prime numbers less than or equal to N is bounded by N/log(N). 

 ## Assuming the lines are parallel to each other .
* To find the coordinates of the intersection of two line segments L1 (x1,x2) and L2 (x3,x4) :

x1 *--------------* x2

         *----------------*
        x3                 x4
        
        
Definitely [x3,x2] is the intersection of L1 and L2.The left border of the intersection is given by max(min(x1,x2),min(x3,x4)) and the right border of the intersection is given by min(max(x1,x2),max(x3,x4)).
 
 (best way to avoid many if else conditions )  :D
left_border   = max(min(x1,x2),min(x3,x4))
right_border  = min(max(x1,x2),max(x3,x4))


The above logic can be extended to 2-D 






 
 
 
