#include "../include/SDLManagment.h"
///////////////////
// public section
//

SDLManagment::SDLManagment():
    WindowID( NULL),
    Events( ),
    STOP(false),
    Picture( NULL),
    FullPicture( ),
    PartPicture( ),
    zoomPicture( ),
    pic( NULL),
    mainDisplayMode( ),
    FULLSCREENFLAG( NULL),
    mouseButtonState( NULL)
{
    if( SDL_Init( SDL_INIT_VIDEO) == -1){
        printSDLError();
    }
    WindowID.clear();
}

SDLManagment::~SDLManagment(){
    clearUp();
    SDL_Quit();
}

const bool SDLManagment::wasInit() const{
    if( pic == 0)
        return false;
    return SDL_WasInit( SDL_INIT_VIDEO);
}

void SDLManagment::Main(){
    if( !wasInit())
        return;
    if( setUp() == false)
        STOP = true;
    while( !STOP){
        handleEvents();
    }
}

void SDLManagment::loadImage( std::string path){
    pic = IMG_Load( path.c_str());
    if( pic == NULL)
        printSDLError();
    else{
        FullPicture.x = 0;
        FullPicture.y = 0;
        FullPicture.w = pic->w;
        FullPicture.h = pic->h;
        PartPicture.x = 0;
        PartPicture.y = 0;
        PartPicture.w = pic->w;
        PartPicture.h = pic->h;
    }
}

////////////////////
// private section
//

const bool SDLManagment::setUp(){
    if( createMainWindow( "SpriteViewerSDL") == false)
        return false;
    return true;
}

const bool SDLManagment::createMainWindow( std::string title){
    SDL_GetDesktopDisplayMode( &mainDisplayMode);
    SDL_WindowID window = SDL_CreateWindow( title.c_str(),
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            ( FULLSCREENFLAG != 0)? mainDisplayMode.w :((pic->w < mainDisplayMode.w)? pic->w : mainDisplayMode.w)
                                            ,( FULLSCREENFLAG != 0)? mainDisplayMode.h : ((pic->h < mainDisplayMode.h)? pic->h : mainDisplayMode.h)
                                            , SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | FULLSCREENFLAG);
    if( FULLSCREENFLAG)
        SDL_SetFullscreenDisplayMode( NULL);
    if( !window){
        printSDLError( "No mainWindow");
        eraseWindow( window);
        return false;
    }

    if ( SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTCOPY) < 0){
        printSDLError( "No mainWindowRenderer");
        SDL_DestroyWindow( window);
        window = NULL;
        eraseWindow( window);
        return false;
    }

    if( window){
        SDL_SelectRenderer( window);
        SDL_RenderFill( NULL);
        SDL_RenderPresent();
        if( FULLSCREENFLAG != 0){
            SDL_GetFullscreenDisplayMode( &mainDisplayMode);
            std::cout << "In fullscreen mode.\n";
        }else{
            SDL_GetDisplayMode( window, &mainDisplayMode);
            std::cout << "In window mode.\n";
        }
        ////
        // ????????????????????????????????????????????????????????????????????????????????????????
        //
        zoomPicture.x = 0;
        zoomPicture.y = 0;
        zoomPicture.w = ( mainDisplayMode.w < FullPicture.w )?mainDisplayMode.w : FullPicture.w;
        zoomPicture.h = ( mainDisplayMode.h < FullPicture.h )?mainDisplayMode.h : FullPicture.h;

        //
        // ????????????????????????????????????????????????????????????????????????????????????????
        ////

        Picture = SDL_CreateTextureFromSurface( mainDisplayMode.format, pic);
        if( !Picture){
            printSDLError( "No TextureFromSurface");
            SDL_FreeSurface( pic);
            pic = 0;
            eraseWindow( window);
            return false;
        }
        SDL_FreeSurface( pic);
        pic = NULL;

        PartPicture.x = 0;
        PartPicture.y = 0;
        PartPicture.w = mainDisplayMode.w;
        PartPicture.h = mainDisplayMode.h;

        FullPicture.x = static_cast<int>(( static_cast<double>( mainDisplayMode.h) * static_cast<double>( FullPicture.w))/ static_cast<double>( FullPicture.h));
        FullPicture.y = static_cast<int>(( static_cast<double>( mainDisplayMode.w) * static_cast<double>( FullPicture.h))/ static_cast<double>( FullPicture.w));

        SDL_RenderCopy( Picture, &PartPicture, &zoomPicture);
        SDL_RenderPresent();
    }
    WindowID.push_back( window);
    return true;
}

const bool SDLManagment::createWindow( std::string title){
    /*SDL_WindowID window = SDL_CreateWindow( title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN |SDL_WINDOW_OPENGL);
    if ( SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTCOPY) < 0){
        printSDLError();
        SDL_DestroyWindow( window);
        window = NULL;
    }

    if( !window)
        printSDLError();
    else{
        WindowID.push_back( window);
        SDL_RenderFill( NULL);
        SDL_RenderPresent();
        SDL_RenderFill( NULL);
        SDL_RenderPresent();
        SDL_RenderFill( NULL);
        SDL_RenderPresent();
        return true;
    }*/
    return false;
}

void SDLManagment::clearUp(){
    while( !WindowID.empty()){
        eraseWindow( WindowID.front());
    }
    WindowID.clear();

    SDL_FreeSurface( pic);
    pic = NULL;
    SDL_DestroyTexture( Picture);
    Picture = NULL;
}

void SDLManagment::eraseWindow( SDL_WindowID& window){
    std::cout << "removing window: " << window << std::endl;
    SDL_DestroyRenderer( window);
    SDL_DestroyWindow( window);
    WindowID.remove( window);
    window = NULL;
}

void SDLManagment::handleEvents(){
    while( SDL_PollEvent( &Events)){
        handleKeyboardEvents();
        handleMouseEvents();
        handleWindowEvents();
    }
}

void SDLManagment::handleKeyboardEvents(){
    if( Events.key.state == SDL_RELEASED){
        switch( Events.key.keysym.sym){
        case SDLK_q:
            STOP = true;
            break;
        default:
            break;
        }
    }
}

void SDLManagment::handleWindowEvents(){
    if( Events.type == SDL_WINDOWEVENT){
        if( Events.window.event == SDL_WINDOWEVENT_CLOSE ){
            eraseWindow( Events.window.windowID);
            if( WindowID.empty())
                STOP = true;
        }
        if( Events.window.event < SDL_WINDOWEVENT_CLOSE)
            refreshWindow( Events.window.windowID);
    }
}

void SDLManagment::handleMouseEvents(){
    switch( Events.type){
    case SDL_MOUSEBUTTONDOWN:
        if( Events.button.windowID == 1){
            if( Events.button.button == 3){
                mouseButtonState += (1 << 3);
            }
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if( Events.button.windowID == 1){
            if( Events.button.button == 3){
                mouseButtonState -= (1 << 3);
            }
        }
        break;
    case SDL_MOUSEMOTION:
        if( Events.motion.windowID == 1){
            if( mouseButtonState & ( 1 << 3))
                movePictureInWindow( Events.motion.windowID, Events.motion.xrel, Events.motion.yrel);
        }
        break;
    case SDL_MOUSEWHEEL:
        zoomPictureInWindow( Events.wheel.windowID, Events.wheel.y);
        break;
    default:
        break;
    }
}

void SDLManagment::refreshWindow( SDL_WindowID& window){
    SDL_SelectRenderer( window);
    SDL_RenderPresent();
}

void SDLManagment::movePictureInWindow( SDL_WindowID& window, signed short int x, signed short int y){
    x = -x;
    y = -y;
    SDL_SelectRenderer( window);
    if( FullPicture.w >= PartPicture.w + PartPicture.x + x && 0 <= PartPicture.x + x){
        PartPicture.x += x;
    }
    if( FullPicture.h >= PartPicture.h + PartPicture.y + y && 0 <= PartPicture.y + y){
        PartPicture.y += y;
    }
    SDL_RenderFill( NULL);
    SDL_RenderCopy( Picture, &PartPicture, &zoomPicture);
    refreshWindow( window);
}

void SDLManagment::zoomPictureInWindow( SDL_WindowID& window, signed long int amount){
    SDL_SelectRenderer( window);
    SDL_GetCurrentDisplayMode( &mainDisplayMode);

        ////
        // ????????????????????????????????????????????????????????????????????????????????????????
        //
    if( amount < 0){
        PartPicture.x = 0;
        PartPicture.y = 0;
        PartPicture.w = FullPicture.w;
        PartPicture.h = FullPicture.h;

        double factorPicture = 0.0;
        double factorDisplay = 0.0;
        factorPicture = static_cast<double>(FullPicture.w) / static_cast<double>(FullPicture.h);
        factorDisplay = static_cast<double>( mainDisplayMode.w) / static_cast<double>( mainDisplayMode.h);

        if( factorPicture > factorDisplay){
            zoomPicture.h = FullPicture.y;
            zoomPicture.y = static_cast<int>( static_cast<double>( mainDisplayMode.h - FullPicture.y) / 2.0);
        }
        if( factorPicture < factorDisplay){
            zoomPicture.w = FullPicture.x;
            zoomPicture.x = static_cast<int>( static_cast<double>( mainDisplayMode.w - FullPicture.x) / 2.0);
        }

    }else{
        zoomPicture.x = 0;
        zoomPicture.y = 0;
        zoomPicture.w = mainDisplayMode.w;
        zoomPicture.h = mainDisplayMode.h;
        PartPicture.x = 0;
        PartPicture.y = 0;
        PartPicture.w = mainDisplayMode.w;
        PartPicture.h = mainDisplayMode.h;
    }
        //
        // ????????????????????????????????????????????????????????????????????????????????????????
        ////

    SDL_RenderFill( NULL);
    SDL_RenderCopy( Picture, &PartPicture, &zoomPicture);
    refreshWindow( window);
}
