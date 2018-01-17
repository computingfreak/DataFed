#include <iostream>
#include <unistd.h>

#include "FacilityServer.hpp"

using namespace std;
using namespace SDMS;

int main( int a_argc, char ** a_argv )
{
    try
    {
        const char * host = "127.0.0.1";
        int port = 5800;
        int timeout = 5;
        int opt;

        while (( opt = getopt( a_argc, a_argv, "?h:p:t:" )) != -1 )
        {
            switch( opt )
            {
            case '?':
                cout << "options:" << endl;
                cout << "? - show help" << endl;
                cout << "h - server hostname" << endl;
                cout << "p - server port" << endl;
                cout << "t - timeout (sec)" << endl;
                return 0;
            case 'h':
                host = optarg;
                break;
            case 'p':
                port = atoi( optarg );
                break;
            case 't':
                timeout = atoi( optarg );
                break;
            }
        }

        Facility::Server server( host, port, timeout );

        server.runWorkerRouter( false );
    }
    catch( exception &e )
    {
        cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}

