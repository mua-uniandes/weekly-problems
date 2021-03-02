import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    1
    val input = BufferedReader( InputStreamReader( System.`in` ) )
    val dayIn = input.readLine()

    val hashMap = HashMap<String, Int>();
    //SUN, MON, TUE, WED, THU, FRI, or SAT
    hashMap.put( "SUN", 7 );
    hashMap.put( "MON", 6 );
    hashMap.put( "TUE", 5 );
    hashMap.put( "WED", 4 );
    hashMap.put( "THU", 3 );
    hashMap.put( "FRI", 2 );
    hashMap.put( "SAT", 1 );

    print( hashMap.get( dayIn ) )

}