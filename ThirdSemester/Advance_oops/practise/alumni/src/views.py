from django.shortcuts import render,redirect
from django.views.generic import TemplateView

# Create your views here.

class Index(TemplateView):
    template_name = "index.html"
    
    
class Display(TemplateView):
    def get(self,request,**kwargs):
        aid = request.GET['aid']
        name = request.GET['name']
        age = request.GET['age']
        address = request.GET['address']
        
        return render(request,'display.html',{'aid':aid,'name':name,'age':age,'address':address})
        
        