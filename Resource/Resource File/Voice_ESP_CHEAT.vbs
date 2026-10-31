Dim speaks, speech
speaks="Welcome To SINKI CHEAT"
set speech=CreateObject("sapi.spvoice")
with speech
       Set.voice = .getvoices.item(0)
       .Volume = 100
       .Rate = +0
   end with
speech.speak speaks