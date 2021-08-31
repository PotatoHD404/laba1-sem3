import {writable, Writable} from "svelte/store";

export const console_text: Writable<string> = writable('');

let text: string = '';

async function updater(){

}