# GiveMiiBBCiPlayer

Since August 31st, 2016 the BBC iPlayer app for the Wii U has been discontinued and the app can no longer be accessed.  
To check if the service is available the BBC iPlayer app requests a service token from `https://account.nintendo.net/v1/api/provider/service_token/` with a BBC iPlayer specific client id.

This endpoint now responds with:

```html
<errors>
    <error>
        <code>0123</code>
        <message>Service has expired</message>
    </error>
</errors>
```

The app then checks if acquiring this token has been sucessful and if not it will display the error. The acquired token itself is not used.  
This is a Wii U Plugin System plugin for Aroma which just makes this request always return sucess and thus allowing the BBC iPlayer app to continue functioning.

This project is a fork of [GiveMiiYouTube](https://github.com/PretendoNetwork/GiveMiiYouTube), a similar project that instead patches the YouTube app.

## Patching the application

Alongside this service token patch, the BBC iPlayer app's config file needs to be modified to re-enable the app. To do this, it's as simple as making it say 'PS4' instead of 'WiiU' in the User Agent field. A Python patcher is in the process of being made to automatically do this for you. But for now, assuming you have the application installed, you can do this via the following:

1. Connect to your Wii U via FTP
2. Navigate to `/storage_mlc/usr/title/00050000/10154800/content/app/config.xml`
3. Search for `<nwf:userAgent>` and replace `(Nintendo WiiU)` with `(PLAYSTATION 4; 8.01)`

## Special Thanks to

[@ashquarky](https://github.com/ashquarky) for the awesome patcher framework which was taken from [Nimble](https://github.com/PretendoNetwork/Nimble).

[@garyodernichts](https://github.com/garyodernichts) for the original patch.

[@internalloss](https://github.com/internalloss) for giving information on how to re-enable the app.

## Building

```bash
# Build docker image (only needed once)
docker build . -t givemiibbciplayer_builder

# make 
docker run -it --rm -v ${PWD}:/project givemiibbciplayer_builder make

# make clean
docker run -it --rm -v ${PWD}:/project givemiibbciplayer_builder make clean
```
