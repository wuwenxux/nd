#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
int main( void )
{
    int sockfd, len;
    struct ifconf ifc;
    struct ifreq* ifr;

    if ( ( sockfd = socket( AF_INET, SOCK_DGRAM, 0 ) ) < 0 )
    printf( "can't create socket" );

    ifc.ifc_len = len = sizeof( struct ifreq );
    ifc.ifc_buf = ( caddr_t ) 0;

    while ( 1 )
    {
    ifc.ifc_buf = ( caddr_t ) realloc( ( void * ) ifc.ifc_buf,
    ifc.ifc_len );
    if ( ifc.ifc_buf == ( caddr_t ) 0 )
    printf( "can't allocate memory" );

    if ( ioctl( sockfd, SIOCGIFCONF, &ifc ) < 0 )
    printf( "can't get SIOCGIFCONF" );

    if ( len > ifc.ifc_len )
    break;

    ifc.ifc_len = len *= 2;
    }

    ifc.ifc_buf = ( caddr_t ) realloc( ( void * ) ifc.ifc_buf, ifc.ifc_len );
    if ( ifc.ifc_buf == ( caddr_t ) 0 )
    printf( "can't allocate memory" );

    for ( ifr = ( struct ifreq * ) ifc.ifc_buf, len = 0;
    len < ifc.ifc_len; ifr++, len += sizeof( struct ifreq ) )
    printf( "%s\n", ifr->ifr_name );

    free( ifc.ifc_buf );
    return 0;
}
