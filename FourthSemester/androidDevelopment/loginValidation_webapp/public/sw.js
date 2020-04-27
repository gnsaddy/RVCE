const staticCacheName = 'site-static-ver1';
const assets = [
	'./',
	'./index.html',
	'./bootstrap/css/bootstrap.css',
	'./bootstrap/js/bootstrap.js',
	'./bootstrap/js/popper.js',
	'./bootstrap/js/jquery-min.js',
	'./successful.html',
	'./unsuccessful.html',
	'./profile.json',
];

// install event
self.addEventListener('install', (evt) => {
	console.log('service worker installed');
	evt.waitUntil(
		caches.open(staticCacheName).then((cache) => {
			console.log('caching shell assets');
			cache.addAll(assets);
		})
	);
});

// activate event
self.addEventListener('activate', (evt) => {
	console.log('service worker activated');
});

// fetch event
self.addEventListener('fetch', (evt) => {
	console.log('fetch event', evt);
	evt.respondWith(
		caches.match(evt.request).then((cacheRes) => {
			return cacheRes || fetch(evt.request);
		})
	);
});
