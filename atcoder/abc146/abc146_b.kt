import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val input = BufferedReader( InputStreamReader( System.`in` ) );
    val N = input.readLine().toInt();
    val S = input.readLine();
    val hashMap = HashMap<Char, Int>();

    val abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    var i = 0;
    while( i < abecedario.length ) {
        hashMap.put( abecedario[ i ], i )
        i++;
    }
    i = 0;
    var newWord = "";
    while( i < S.length ) {
        newWord += abecedario[ ( hashMap.get( S[ i ] )!! + N )  % abecedario.length  ] ;
        i++;
    }
    print( newWord )
}