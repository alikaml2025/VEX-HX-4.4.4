Dim speaks, speech
speaks="Please Install The Ad Blocker Extension!, If it is already installed please remove and reinstall, Because some problems have been found, I Hope You Understand"
set speech=CreateObject("sapi.spvoice")
with speech
       Set.voice = .getvoices.item(0)
       .Volume = 100
       .Rate = +0
   end with
speech.speak speaks