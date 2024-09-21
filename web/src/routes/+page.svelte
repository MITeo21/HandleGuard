<script>
  import {
    MapLibre,
    DefaultMarker,
    Popup,
    GeoJSON,
    LineLayer,
  } from "svelte-maplibre";
  import { fade } from "svelte/transition";
  import logo from "$lib/images/icon.png";

  let mapClasses = "";
  let markers = [
    {
      lngLat: [-0.1709, 51.479],
      name: "Marker 1",
    },
    {
      lngLat: [-0.177753459872946, 51.498208544108934],
      name: "Marker 3",
    },
  ];

  let data = {
    type: "FeatureCollection",
    features: [
      {
        type: "Feature",
        properties: {},
        geometry: {
          coordinates: [
            [-0.17029436886616622, 51.47877235398511],
            [-0.1758454622781187, 51.48446211324952],
            [-0.1747945558847448, 51.48500241090164],
            [-0.175359675624577, 51.48535180983828],
            [-0.17646402486727197, 51.48653164969471],
            [-0.17819844074713842, 51.4877296061122],
            [-0.17971660160876013, 51.4887727189066],
            [-0.1811038865349417, 51.491038147306455],
            [-0.18024010520895217, 51.49131520892257],
            [-0.17848636766126447, 51.49206488969375],
            [-0.17961189816969636, 51.49804559304056],
            [-0.177753459872946, 51.498208544108934],
          ],
          type: "LineString",
        },
      },
    ],
  };

  let showSplash = true;
  let angle = 120;

  //   setInterval(() => {
  //     angle++;
  //     console.log(angle);
  //   }, 100);

  setInterval(() => {
    showSplash = false;
  }, 3000);

  let socket = new WebSocket("ws://192.168.63.128/ws");

  socket.onopen = function (e) {
    console.log("[open] Connection established");
    console.log("Sending to server");
    socket.send("My name is John");
  };

  socket.onmessage = function (event) {
    console.log(`[message] Data received from server: ${event.data}`);
    angle = event.data;
  };

  socket.onclose = function (event) {
    if (event.wasClean) {
      console.log(
        `[close] Connection closed cleanly, code=${event.code} reason=${event.reason}`,
      );
    } else {
      // e.g. server process killed or network down
      // event.code is usually 1006 in this case
      console.log("[close] Connection died");
    }
  };

  socket.onerror = function (error) {
    console.log(`[error]`);
  };
</script>

<svelte:head>
  <title>Home</title>
  <meta name="description" content="Svelte demo app" />
</svelte:head>

<MapLibre
  style="https://basemaps.cartocdn.com/gl/positron-gl-style/style.json"
  class={mapClasses}
  standardControls
  zoom={13}
  center={[-0.17514, 51.48973]}
>
  {#each markers as { lngLat, name }}
    <!-- Unlike the custom marker example, default markers do not have mouse events,
    and popups only support the default openOn="click" behavior -->
    <DefaultMarker {lngLat} draggable>
      <Popup offset={[0, -10]}>
        <div class="text-lg font-bold">{name}</div>
      </Popup>
    </DefaultMarker>
  {/each}

  <GeoJSON id="maine" {data}>
    <LineLayer
      layout={{ "line-cap": "round", "line-join": "round" }}
      paint={{
        "line-width": 5,
        "line-color": "#586F7C",
        "line-opacity": 0.8,
      }}
    />
  </GeoJSON>
</MapLibre>

<div class="compass">
  <div class="compass__arrow" style={"rotate:" + angle + "deg"}></div>
</div>

{#if showSplash}
  <div class="splash" transition:fade={{ delay: 250, duration: 300 }}>
    <img src={logo} alt="logo" />
    <h1>Cycle Guard</h1>
  </div>
{/if}

<style>
  :global(.map) {
    height: 500px;
  }

  .compass {
    position: absolute;
    bottom: 30px;
    right: 10px;
    width: 70px;
    height: 70px;
    background-color: white;
    border-radius: 50%;
    box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
    z-index: 5;
  }

  .compass__arrow {
    width: 0;
    height: 0;
    border-left: 20px solid transparent;
    border-right: 20px solid transparent;
    border-top: 20px solid #586f7c;
    position: absolute;
    top: 50%;
    left: 50%;
    translate: -50% -50%;
    transform-origin: 50% 50%;
  }

  .splash {
    position: fixed;
    top: 0;
    left: 0;
    width: 100vw;
    height: 100vh;
    background-color: #fff;
    display: flex;
    justify-content: center;
    align-items: center;
    z-index: 999;
    flex-direction: column;
  }

  .splash h1 {
    font-size: 3rem;
    color: #586f7c;
    font-weight: bold;
    margin-top: 1em;
  }
</style>
