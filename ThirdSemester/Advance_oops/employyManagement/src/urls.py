from django.contrib import admin
from django.urls import path
from src import views
from src.views import HomePage


urlpatterns = [
    path('admin/', admin.site.urls),
    path('', HomePage.as_view(), name='index'),
    path('upload/', views.upload, name='upload'),
    path('display/', views.display, name='display'),

]
